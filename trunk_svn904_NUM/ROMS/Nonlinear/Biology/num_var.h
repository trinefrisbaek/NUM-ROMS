/*
** svn $Id: fennel_var.h 889 2018-02-10 03:32:52Z arango $
*************************************************** Hernan G. Arango ***
** Copyright (c) 2002-2018 The ROMS/TOMS Group                        **
**   Licensed under a MIT/X style license                             **
**   See License_ROMS.txt                                             **
************************************************************************
**                                                                    **
**  Assigns metadata indices for the Fennel et al. (2006) ecosystem   **
**  model variables that are used in input and output NetCDF files.   **
**  The metadata information is read from "varinfo.dat".              **
**                                                                    **
**  This file is included in file "mod_ncparam.F", routine            **
**  "initialize_ncparm".                                              **
**                                                                    **
************************************************************************
*/

/*
**  Model state biological tracers.
*/
            CASE ('idTvar(iNO3_)')
              idTvar(iNO3_)=varid
            CASE ('idTvar(iNH4_)')
              idTvar(iNH4_)=varid
            CASE ('idTvar(iDOC_)')
              idTvar(iDOC_)=varid
            CASE ('idTvar(iChlo)')
              idTvar(iChlo)=varid
            CASE ('idTvar(iSDeN)')
              idTvar(iSDeN)=varid
            CASE ('idTvar(iLDeN)')
              idTvar(iLDeN)=varid
/* Model state biological Size tracers */
            CASE ('idTvar(iB001)')
              idTvar(iB001)=varid
            CASE ('idTvar(iB002)')
              idTvar(iB002)=varid
            CASE ('idTvar(iB003)')
              idTvar(iB003)=varid
            CASE ('idTvar(iB004)')
              idTvar(iB004)=varid
            CASE ('idTvar(iB005)')
              idTvar(iB005)=varid
            CASE ('idTvar(iB006)')
              idTvar(iB006)=varid
            CASE ('idTvar(iB007)')
              idTvar(iB007)=varid
            CASE ('idTvar(iB008)')
              idTvar(iB008)=varid
            CASE ('idTvar(iB009)')
              idTvar(iB009)=varid
            CASE ('idTvar(iB010)')
              idTvar(iB010)=varid
/* End of model state biological Size tracers */

/*
**  Adjoint sensitivity state biological tracers.
*/

#if defined AD_SENSITIVITY   || defined IS4DVAR_SENSITIVITY || \
    defined OPT_OBSERVATIONS || defined SENSITIVITY_4DVAR   || \
    defined SO_SEMI

#endif

/*
**  Biological tracers open boundary conditions.
*/

            CASE ('idTbry(iwest,iNO3_)')
              idTbry(iwest,iNO3_)=varid
            CASE ('idTbry(ieast,iNO3_)')
              idTbry(ieast,iNO3_)=varid
            CASE ('idTbry(isouth,iNO3_)')
              idTbry(isouth,iNO3_)=varid
            CASE ('idTbry(inorth,iNO3_)')
              idTbry(inorth,iNO3_)=varid

            CASE ('idTbry(iwest,iNH4_)')
              idTbry(iwest,iNH4_)=varid
            CASE ('idTbry(ieast,iNH4_)')
              idTbry(ieast,iNH4_)=varid
            CASE ('idTbry(isouth,iNH4_)')
              idTbry(isouth,iNH4_)=varid
            CASE ('idTbry(inorth,iNH4_)')
              idTbry(inorth,iNH4_)=varid

            CASE ('idTbry(iwest,iDOC_)')
              idTbry(iwest,iDOC_)=varid
            CASE ('idTbry(ieast,iDOC_)')
              idTbry(ieast,iDOC_)=varid
            CASE ('idTbry(isouth,iDOC_)')
              idTbry(isouth,iDOC_)=varid
            CASE ('idTbry(inorth,iDOC_)')
              idTbry(inorth,iDOC_)=varid

            CASE ('idTbry(iwest,iSDeN)')
              idTbry(iwest,iSDeN)=varid
            CASE ('idTbry(ieast,iSDeN)')
              idTbry(ieast,iSDeN)=varid
            CASE ('idTbry(isouth,iSDeN)')
              idTbry(isouth,iSDeN)=varid
            CASE ('idTbry(inorth,iSDeN)')
              idTbry(inorth,iSDeN)=varid

            CASE ('idTbry(iwest,iLDeN)')
              idTbry(iwest,iLDeN)=varid
            CASE ('idTbry(ieast,iLDeN)')
              idTbry(ieast,iLDeN)=varid
            CASE ('idTbry(isouth,iLDeN)')
              idTbry(isouth,iLDeN)=varid
            CASE ('idTbry(inorth,iLDeN)')
              idTbry(inorth,iLDeN)=varid

            CASE ('idTbry(iwest,iChlo)')
              idTbry(iwest,iChlo)=varid
            CASE ('idTbry(ieast,iChlo)')
              idTbry(ieast,iChlo)=varid
            CASE ('idTbry(isouth,iChlo)')
              idTbry(isouth,iChlo)=varid
            CASE ('idTbry(inorth,iChlo)')
              idTbry(inorth,iChlo)=varid

/* Biological tracer Size classes open boundary */
            CASE ('idTbry(iwest,iB001)')
              idTbry(iwest,iB001)=varid
            CASE ('idTbry(ieast,iB001)')
              idTbry(ieast,iB001)=varid
            CASE ('idTbry(isouth,iB001)')
              idTbry(isouth,iB001)=varid
            CASE ('idTbry(inorth,iB001)')
              idTbry(inorth,iB001)=varid

            CASE ('idTbry(iwest,iB002)')
              idTbry(iwest,iB002)=varid
            CASE ('idTbry(ieast,iB002)')
              idTbry(ieast,iB002)=varid
            CASE ('idTbry(isouth,iB002)')
              idTbry(isouth,iB002)=varid
            CASE ('idTbry(inorth,iB002)')
              idTbry(inorth,iB002)=varid

            CASE ('idTbry(iwest,iB003)')
              idTbry(iwest,iB003)=varid
            CASE ('idTbry(ieast,iB003)')
              idTbry(ieast,iB003)=varid
            CASE ('idTbry(isouth,iB003)')
              idTbry(isouth,iB003)=varid
            CASE ('idTbry(inorth,iB003)')
              idTbry(inorth,iB003)=varid

            CASE ('idTbry(iwest,iB004)')
              idTbry(iwest,iB004)=varid
            CASE ('idTbry(ieast,iB004)')
              idTbry(ieast,iB004)=varid
            CASE ('idTbry(isouth,iB004)')
              idTbry(isouth,iB004)=varid
            CASE ('idTbry(inorth,iB004)')
              idTbry(inorth,iB004)=varid

            CASE ('idTbry(iwest,iB005)')
              idTbry(iwest,iB005)=varid
            CASE ('idTbry(ieast,iB005)')
              idTbry(ieast,iB005)=varid
            CASE ('idTbry(isouth,iB005)')
              idTbry(isouth,iB005)=varid
            CASE ('idTbry(inorth,iB005)')
              idTbry(inorth,iB005)=varid

            CASE ('idTbry(iwest,iB006)')
              idTbry(iwest,iB006)=varid
            CASE ('idTbry(ieast,iB006)')
              idTbry(ieast,iB006)=varid
            CASE ('idTbry(isouth,iB006)')
              idTbry(isouth,iB006)=varid
            CASE ('idTbry(inorth,iB006)')
              idTbry(inorth,iB006)=varid

            CASE ('idTbry(iwest,iB007)')
              idTbry(iwest,iB007)=varid
            CASE ('idTbry(ieast,iB007)')
              idTbry(ieast,iB007)=varid
            CASE ('idTbry(isouth,iB007)')
              idTbry(isouth,iB007)=varid
            CASE ('idTbry(inorth,iB007)')
              idTbry(inorth,iB007)=varid

            CASE ('idTbry(iwest,iB008)')
              idTbry(iwest,iB008)=varid
            CASE ('idTbry(ieast,iB008)')
              idTbry(ieast,iB008)=varid
            CASE ('idTbry(isouth,iB008)')
              idTbry(isouth,iB008)=varid
            CASE ('idTbry(inorth,iB008)')
              idTbry(inorth,iB008)=varid

            CASE ('idTbry(iwest,iB009)')
              idTbry(iwest,iB009)=varid
            CASE ('idTbry(ieast,iB009)')
              idTbry(ieast,iB009)=varid
            CASE ('idTbry(isouth,iB009)')
              idTbry(isouth,iB009)=varid
            CASE ('idTbry(inorth,iB009)')
              idTbry(inorth,iB009)=varid

            CASE ('idTbry(iwest,iB010)')
              idTbry(iwest,iB010)=varid
            CASE ('idTbry(ieast,iB010)')
              idTbry(ieast,iB010)=varid
            CASE ('idTbry(isouth,iB010)')
              idTbry(isouth,iB010)=varid
            CASE ('idTbry(inorth,iB010)')
              idTbry(inorth,iB010)=varid

/* End of biological tracer Size classes open boundary */

/*
**  Biological tracers point Source/Sinks (river runoff).
*/

              CASE ('idRtrc(iNO3_)')
                idRtrc(iNO3_)=varid
              CASE ('idRtrc(iNH4_)')
                idRtrc(iNH4_)=varid
              CASE ('idRtrc(iLDeN)')
                idRtrc(iLDeN)=varid
              CASE ('idRtrc(iSDeN)')
                idRtrc(iSDeN)=varid
              CASE ('idRtrc(iChlo)')
                idRtrc(iChlo)=varid
#ifdef CARBON
              CASE ('idRtrc(iTIC_)')
                idRtrc(iTIC_)=varid
              CASE ('idRtrc(iTAlk)')
                idRtrc(iTAlk)=varid
              CASE ('idRtrc(iLDeC)')
                idRtrc(iLDeC)=varid
              CASE ('idRtrc(iSDeC)')
                idRtrc(iSDeC)=varid
#endif
#ifdef OXYGEN
              CASE ('idRtrc(iOxyg)')
                idRtrc(iOxyg)=varid
#endif


#ifdef DIAGNOSTICS_BIO

/*
**  Biological tracers term diagnostics.
*/
#endif
