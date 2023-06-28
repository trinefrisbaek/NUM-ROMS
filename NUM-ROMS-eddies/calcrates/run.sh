#!/bin/sh
set -e
# redo make to change the path for the input file
make -f makefile

# create netcdf file for the data we will be looking at
#cdo select,timestep=-1 tmp_netcdf/combi.nc tmp_netcdf/thistimestep.nc
#ncks --msa_usr_rdr -d ocean_time,57,57 tmp_netcdf/ocean_his_0003.nc tmp_netcdf/thistimestep.nc
#ncks -A tmp_netcdf/z_w1.nc tmp_netcdf/thistimestep.nc
./getrates

