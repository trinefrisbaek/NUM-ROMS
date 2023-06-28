program NUMmodeltest2
  use NUMmodel
  use globals
  use mynetcdf

  implicit none

  real(dp), allocatable :: u0(:), u00(:,:,:,:), nc_tmp(:,:,:), nc_temp(:,:,:), z_w(:,:,:), dudt(:)
  real(dp), allocatable :: JN(:,:,:,:), JL(:,:,:,:), JLreal(:,:,:,:), JDOC(:,:,:,:), JLossPass(:,:,:,:)
  real(dp), allocatable :: JF(:,:,:,:), Jtot(:,:,:,:), mortpred(:,:,:,:), mortHTL(:,:,:,:), jPOM(:,:,:,:)
  real(dp), allocatable :: parout(:,:,:)
  integer:: nBio,nDet,i
  integer :: kk
  character(len=4) :: thispar
  character(len=3) :: thisnum
  integer,          parameter :: NX        = 232       ! Number of columns.
  integer,          parameter :: NY        = 120         ! Number of rows.
  integer,          parameter :: NZ        = 20         ! Number of rows.
  integer :: x, y, z
  real(dp) :: top_light,mypar,Att_fac,ExpAtt_fac,top_thiscell
  nBio = 10
  nDet = 2
  kk = 3.0
  call setupGeneralistsPOM(nBio,nDet)

  allocate(nc_tmp(NX,NY,NZ))
  allocate(nc_temp(NX,NY,NZ))
  allocate(z_w(NX,NY,NZ+1))
  allocate(u0(nGrid))
  allocate(u00(nGrid,NX,NY,NZ))
  allocate(dudt(nGrid))
  allocate(JN(nBio,NX,NY,NZ))
  allocate(JL(nBio,NX,NY,NZ))
  allocate(JLreal(nBio,NX,NY,NZ))
  allocate(JDOC(nBio,NX,NY,NZ))
  allocate(JLossPass(nBio,NX,NY,NZ))
  allocate(JF(nBio,NX,NY,NZ))
  allocate(Jtot(nBio,NX,NY,NZ))
  allocate(mortpred(nBio,NX,NY,NZ))
  allocate(mortHTL(nBio,NX,NY,NZ))
  allocate(jPOM(nBio,NX,NY,NZ))
  allocate(parout(NX,NY,NZ))
  
  call getnetcdf(nc_tmp,'NO3')
  u00(idxN,:,:,:)=nc_tmp*14.0067d0 
  call getnetcdf(nc_tmp,'DOC')
  u00(idxDOC,:,:,:)=nc_tmp*12.0107d0

  do i = 1,nBio
     write(thisnum,'(I0.3)') i
     thispar="B"//thisnum
     call getnetcdf(nc_tmp,thispar)
     u00(2+i,:,:,:)=nc_tmp*12.0107d0
  end do
 
  call getnetcdf(nc_tmp,'SdetritusN')
  u00(nBio+1,:,:,:)=nc_tmp/16.0d0*106.0d0*12.0107d0

  call getnetcdf(nc_tmp,'LdetritusN')
  u00(nBio+2,:,:,:)=nc_tmp/16.0d0*106.0d0*12.0107d0
  
  !do z = 1, NZ
  !    do y = 1, NY
  !        do x = 1, NX
  !            write (*, *) u00(13,x, y, z)
  !       end do
  !    end do
  !end do
   
  call getnetcdf(nc_temp,'temp')
  call getnetcdf(z_w,'z_w')

  select type (spec => group(1)%spec)
  type is (spectrumGeneralists)
  do x = 1, NX
      do y = 1, NY
          top_light=0.43d0*150.0d0*1025.0d0*3985.0d0
          mypar=top_light
          do z = NZ,1,-1
            Att_fac=(0.04d0+0.00003d0*sum(u00(3:12,x,y,z)))*  &
     &               (z_w(x,y,z)-z_w(x,y,z-1))
             ExpAtt_fac=EXP(-Att_fac)
             top_thiscell=mypar
             mypar=4.57d0*top_thiscell*(1.0d0-ExpAtt_fac)/Att_fac    ! average at cell center
             parout(x,y,z)=mypar 
            dudt = 0.0d0
            call calcDerivatives(u00(:,x,y,z), mypar, nc_temp(x,y,z), 0.0035d0, dudt)
             mypar=top_thiscell*ExpAtt_fac
             JN(:,x,y,z) = spec%JN / spec%m
             JL(:,x,y,z) = spec%JL / spec%m
             JLreal(:,x,y,z) = spec%JLreal / spec%m
             JDOC(:,x,y,z) = spec%JDOC / spec%m
             JLossPass(:,x,y,z) = spec%JlossPassive / spec%m
             JF(:,x,y,z) =  spec%JF / spec%m
             Jtot(:,x,y,z) =  spec%Jtot / spec%m
             mortpred(:,x,y,z) =  spec%mortpred
             mortHTL(:,x,y,z) =  spec%mortHTL
             jPOM(:,x,y,z) =  spec%jPOM
             !call spec%printRatesUnicellular()
           end do
       end do
   end do

!  select type (spec => group(1)%spec)
!      type is (spectrumGeneralists)
!        call spec%printRatesUnicellular()
  end select
  !call export_light_array('rates/light.nc',parout,'PAR')
  call export_int_array('rates/JN.nc',JN,'JN')
  call export_int_array('rates/JL.nc',JL,'JL')
  call export_int_array('rates/JLreal.nc',JLreal,'JLreal')
  call export_int_array('rates/JDOC.nc',JDOC,'JDOC')
  call export_int_array('rates/JLossPass.nc',JLossPass,'JLossPass')
  call export_int_array('rates/JF.nc',JF,'JF')
  call export_int_array('rates/Jtot.nc',Jtot,'Jtot')
  call export_int_array('rates/mortpred.nc',mortpred,'mortpred')
  call export_int_array('rates/mortHTL.nc',mortHTL,'mortHTL')
  call export_int_array('rates/jPOM.nc',jPOM,'jPOM')
 
  end program NUMmodeltest2
