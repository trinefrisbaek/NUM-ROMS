/*
** svn $Id: upwelling.h 893 2018-02-11 03:54:11Z arango $
*******************************************************************************
** Copyright (c) 2002-2018 The ROMS/TOMS Group                               **
**   Licensed under a MIT/X style license                                    **
**   See License_ROMS.txt                                                    **
*******************************************************************************
**
** Options for Upwelling Test.
**
** Application flag:   UPWELLING
** Input script:       ocean_upwelling.in
*/
#define SOLVE3D
#define UV_ADV
#define NONLIN_EOS
#define UV_QDRAG
#define UV_VIS2
#define MIX_S_UV
#undef MIX_GEO_UV

#define UV_SMAGORINSKY
#define UV_COR
#define DJ_GRADPS
#undef TS_A4HADVECTION
#undef TS_A4VADVECTION
#define MPDATA
#define TS_MPDATA
#define TS_DIF2
#define MIX_GEO_TS
#define K_GSCHEME
#define UV_C4ADVECTION

#define GLS_MIXING
#undef MY25_MIXING
#undef LMD_MIXING
!#define SPLINES_VDIFF
!#define SPLINES_VVISC

#define SALINITY

#define ANA_GRID
#define SRELAXATION
#define SOLAR_SOURCE
!#define ANA_INITIAL
#define ANA_SMFLUX
!#define ANA_STFLUX
!#define ANA_SSFLUX
#define ANA_BTFLUX
#define ANA_BSFLUX

#if defined GLS_MIXING || defined MY25_MIXING
# define KANTHA_CLAYSON
# define N2S2_HORAVG
# define RI_SPLINES
#else
# define ANA_VMIX
#endif

#if defined BIO_NUM
# define POM
# define ANA_SPFLUX
# define ANA_BPFLUX
#endif
