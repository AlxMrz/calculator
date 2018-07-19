## -*- Makefile -*-
##
## User: alexandr
## Time: Jul 19, 2018 4:18:57 PM
## Makefile created by Oracle Developer Studio.
##
## This file is generated automatically.
##


#### Compiler and tool definitions shared by all build targets #####
CCC = g++
CXX = g++
BASICOPTS = -g
CCFLAGS = $(BASICOPTS) -std=c++11
CXXFLAGS = $(BASICOPTS) -std=c++11
CCADMIN = 


# Define the target directories.
TARGETDIR_calculator=GNU-amd64-Linux


all: $(TARGETDIR_calculator)/calculator

## Target: calculator
CPPFLAGS_calculator = 
OBJS_calculator =  \
	$(TARGETDIR_calculator)/main.o
USERLIBS_calculator =  $(SYSLIBS_calculator) core/App.h core/App.cpp core/UI.h core/UI.cpp core/Calculator.h core/Calculator.cpp -lfltk
DEPLIBS_calculator =   
LDLIBS_calculator = $(USERLIBS_calculator)


# Link or archive
$(TARGETDIR_calculator)/calculator: $(TARGETDIR_calculator) $(OBJS_calculator) $(DEPLIBS_calculator)
	$(LINK.cc) $(CCFLAGS_calculator) $(CPPFLAGS_calculator) -o $@ $(OBJS_calculator) $(LDLIBS_calculator)


# Compile source files into .o files
$(TARGETDIR_calculator)/main.o: $(TARGETDIR_calculator) main.cpp
	$(COMPILE.cc) $(CCFLAGS_calculator) $(CPPFLAGS_calculator) -o $@ main.cpp



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_calculator)/calculator \
		$(TARGETDIR_calculator)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_calculator)


# Create the target directory (if needed)
$(TARGETDIR_calculator):
	mkdir -p $(TARGETDIR_calculator)


# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-amd64-Linux

