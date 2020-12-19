CC=c++
BUILDDIR ?= build
INCDIR ?= .
SRCS := containers_demo.cpp
DIR_TEST := test
CXXFLAGS=-I$(INCDIR)
TESTFLAGS=-lboost_unit_test_framework
SRC_TEST ?= $(DIR_TEST)/vec3_test.cpp
EXEC_TEST ?= vec3_test

$(BUILDDIR)/containers_demo:
	$(MKDIR_P) $(dir $@)
	$(CC) $(SRCS) -o $@ $(CXXFLAGS)

$(BUILDDIR)/$(EXEC_TEST):
	$(MKDIR_P) $(dir $@)
	$(CC) $(CXXFLAGS) $(SRC_TEST) $(TESTFLAGS) -o $@

.PHONY: test
test: $(BUILDDIR)/$(EXEC_TEST)
	$(BUILDDIR)/$(EXEC_TEST)

.PHONY: clean
clean:
	$(RM) -r $(BUILDDIR)

MKDIR_P ?= mkdir -p
