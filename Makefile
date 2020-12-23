CPP=c++
BUILDDIR ?= build
INCDIR ?= .
HEADERS=Containers.hpp Shapes.hpp vec.hpp
CXXFLAGS=-I$(INCDIR)
SRCS := vec.cpp Shapes.cpp
OBJS := $(addprefix $(BUILDDIR)/, $(SRCS:.cpp=.o))
TARGETS := containers_demo
TARGET_SRC := containers_demo.cpp
DIR_TEST := test
TESTFLAGS=-lboost_unit_test_framework --coverage
SRC_TEST = $(wildcard $(DIR_TEST)/*.cpp)
EXEC_TEST = $(patsubst $(DIR_TEST)/%.cpp,$(BUILDDIR)/%,$(SRC_TEST))
ALLOBJS = $(addsuffix .o, $(EXEC_TEST)) $(addsuffix .o, $(TARGETS)) $(OBJS)

.PHONY: $(BUILDDIR)

all: $(BUILDDIR) $(BUILDDIR)/$(TARGETS)

$(BUILDDIR)/$(TARGETS): $(addprefix $(BUILDDIR)/, $(TARGETS:=.o)) $(OBJS) $(BUILDDIR) 
	$(MKDIR_P) $(BUILDDIR)
	$(CPP) $(CXXFLAGS) $(OBJS) $< $(TESTFLAGS) -o $@ 

$(BUILDDIR)/%_test: $(BUILDDIR)/%_test.o $(OBJS) $(BUILDDIR) 
	$(CPP) $(CXXFLAGS) $(OBJS) $< $(TESTFLAGS) -o $@

$(BUILDDIR)/%_test.o: $(DIR_TEST)/%_test.cpp
	$(CPP) $(CXXFLAGS) -c -o $@ $< $(TESTFLAGS)

$(BUILDDIR)/%.o: %.cpp
	$(CPP) $(CXXFLAGS) -c -o $@ $< $(TESTFLAGS)

%.gcda: $(BUILDDIR)/%
	$<

$(BUILDDIR)/%.gcda: $(BUILDDIR)/%
	$<

.PRECIOUS: $(ALLOBJS)

.PHONY: test
test: $(BUILDDIR) $(EXEC_TEST)
	./runTests.sh

.PHONY: coverage
#coverage: $(ALLOBJS:.o=.gcda)
coverage:
	./runTests.sh
	./build/containers_demo
	lcov --capture --directory $(BUILDDIR) -b . --output-file $(BUILDDIR)/coverage.info
	lcov --remove $(BUILDDIR)/coverage.info -o $(BUILDDIR)/stripped_coverage.info "/usr/include/*"
	genhtml $(BUILDDIR)/stripped_coverage.info --output-dir $(BUILDDIR)/reports

.PHONY: clean
clean:
	$(RM) -r $(BUILDDIR) *gcda *gcno

MKDIR_P ?= mkdir -p

$(BUILDDIR):
	$(MKDIR_P) $(BUILDDIR)
