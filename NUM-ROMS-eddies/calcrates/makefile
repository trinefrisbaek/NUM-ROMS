#
# Try to determine the operating system:
#
ifeq '$(findstring ;,$(PATH))' ';'
    UNAME := Windows
else
    UNAME := $(shell uname 2>/dev/null || echo Unknown)
    ifeq ($(UNAME), Unknown) 
        UNAME := Windows # Assuming windows if we cannot find a uname
        $(warning    Cannot determine system; assuming Windows)
    endif
endif

$(info    System is $(UNAME))

# Check for other windows name
ifeq ($(findstring NT-,$(UNAME)),NT-)
    # Found
    UNAME=Windows
endif

FORT=gfortran
FLAGS= -fPIC -O2 -I/usr/local/include -L/usr/local/lib/ -lnetcdff

SRCPATH = /scratch/trunk_svn904_NUM/ROMS/External/num

OBJ = input.o $(SRCPATH)/mynetcdf.o $(SRCPATH)/globals.o $(SRCPATH)/spectrum.o $(SRCPATH)/generalists.o $(SRCPATH)/diatoms_simple.o $(SRCPATH)/diatoms.o $(SRCPATH)/generalists_csp.o $(SRCPATH)/copepods.o $(SRCPATH)/POM.o $(SRCPATH)/NUMmodel.o 

all: NUMmodel 

debugging: FLAGS=-fPIC -g3 -fbacktrace#-debug extended # -check all -fpe0 -warn -traceback -I/usr/local/include -L/usr/local/lib/ -lnetcdff

debugging:  all

%.o: %.f90
	$(FORT) -c  $(FLAGS) -o $@ $<

NUMmodel: $(OBJ)  $(SRCPATH)/NUMmodeltest.o
	$(FORT) $(FLAGS) -o getrates $^

clean:
	rm -f *.o NUMmodel
