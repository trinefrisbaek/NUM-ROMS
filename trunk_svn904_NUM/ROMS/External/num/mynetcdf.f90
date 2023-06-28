!
! Module to handle the reading of the input file
!
module mynetcdf
  use globals
  use netcdf
    implicit none
    character(len=*), parameter :: FILE_NAME = 'tmp_netcdf/thistimestep.nc' ! Export/import file.
    character(len=*), parameter :: FILE_NAME2 = 'test.nc' ! Export/import file.
    integer :: ncid
    !integer,          parameter :: NX        = 182       ! Number of columns.
    !integer,          parameter :: NY        = 120         ! Number of rows.
    !integer,          parameter :: NZ        = 20         ! Number of rows.

    !integer :: array(NX, NY, NZ)
    !real(dp), dimension(NX,NY,NZ) :: nc_temp, nc_NO3
    !:wq
!integer :: x, y, z
contains
    subroutine getnetcdf(nc_tmp,thispar)
    character(len=4) :: mypar
    character(len=3) :: thisnum
    real(dp), intent(inout) :: nc_tmp(:,:,:)
    character(len=*), intent(in) :: thispar
    integer :: i

    call import_int_array(FILE_NAME, nc_tmp, thispar)

!    call export_int_array(FILE_NAME2, array, 'temp')
    
    end subroutine getnetcdf
    subroutine check(stat)
        integer, intent(in) :: stat

        if (stat /= NF90_NOERR) then
            print '(a)', trim(nf90_strerror(stat))
            stop
        end if
    end subroutine check

    subroutine import_int_array(file_name, array, var_name)
        character(len=*), intent(in)    :: file_name
        real(dp), intent(inout) :: array(:, :, :)
        character(len=*), intent(in)    :: var_name
        integer                         :: ncid, varid

        ! Open the NetCDF file read-only.
        call check(nf90_open(file_name, NF90_NOWRITE, ncid))

        ! Get the `varid` of the data variable, based on its name.
        call check(nf90_inq_varid(ncid, var_name, varid))
    !    PRINT *, varid
        ! Read the data.
        call check(nf90_get_var(ncid, varid, array))
        !PRINT *, array
        ! Close the file.
        call check(nf90_close(ncid))
    end subroutine import_int_array


   subroutine export_int_array(file_name,array, var_name)
        character(len=*), intent(in)    :: file_name
        real(dp), intent(inout) :: array(:, :, :, :)
        character(len=*), intent(in)    :: var_name
        integer                         :: ncid,varid
        integer                         :: n_dimid, x_dimid, y_dimid, z_dimid

        ! Create the NetCDF file. Override file, if it already exists.
        call check(nf90_create(file_name, NF90_CLOBBER, ncid))

        ! Define the dimensions. NetCDF returns the IDs `x_dimid` and
        ! `y_dimid`.
        call check(nf90_def_dim(ncid, 'n', size(array, 1), n_dimid))
        call check(nf90_def_dim(ncid, 'lon_rho', size(array, 2), x_dimid))
        call check(nf90_def_dim(ncid, 'lat_rho', size(array, 3), y_dimid))
        call check(nf90_def_dim(ncid, 's_rho', size(array, 4), z_dimid))

        ! Define the variable type (NF90_INT: 4-byte integer).
        call check(nf90_def_var(ncid, var_name, NF90_REAL, [n_dimid,x_dimid,y_dimid,z_dimid ], varid))

        ! End define mode.
        call check(nf90_enddef(ncid))

        ! Write the data to the file.
        call check(nf90_put_var(ncid, varid, array))

        ! Close the file.
        call check(nf90_close(ncid))
    end subroutine export_int_array

   subroutine export_light_array(file_name,array, var_name)
        character(len=*), intent(in)    :: file_name
        real(dp), intent(inout) :: array(:, :, :)
        character(len=*), intent(in)    :: var_name
        integer                         :: ncid,varid
        integer                         :: x_dimid, y_dimid, z_dimid

        print*, "Create the NetCDF file. Override file, if it already exists"
        call check(nf90_create(file_name, NF90_CLOBBER, ncid))

        ! Define the dimensions. NetCDF returns the IDs `x_dimid` and
        ! `y_dimid`.
        print*, "Define dims"
        call check(nf90_def_dim(ncid, 'lon_rho', size(array, 1), x_dimid))
        call check(nf90_def_dim(ncid, 'lat_rho', size(array, 2), y_dimid))
        call check(nf90_def_dim(ncid, 's_rho', size(array, 3), z_dimid))

        ! Define the variable type (NF90_INT: 4-byte integer).
        print*, "define var type"
        call check(nf90_def_var(ncid, var_name, NF90_REAL,[x_dimid,y_dimid,z_dimid ], varid))

        ! End define mode.
        call check(nf90_enddef(ncid))

        ! Write the data to the file.
        print*, "write data"
        call check(nf90_put_var(ncid, varid, array))

        ! Close the file.
        call check(nf90_close(ncid))
    end subroutine export_light_array


end module mynetcdf
