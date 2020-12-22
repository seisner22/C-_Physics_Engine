CC=c++
BUILDDIR ?= build
INCDIR ?= .
SRCS := vec.cpp Shapes.cpp containers_demo.cpp
DIR_TEST := test
CXXFLAGS=-I$(INCDIR)
TESTFLAGS=-lboost_unit_test_framework -lgcov --coverage
SRC_TEST ?= $(DIR_TEST)/vec3_test.cpp
EXEC_TEST ?= vec3_test

$(BUILDDIR)/containers_demo: $(SRCS)
	$(MKDIR_P) $(dir $@)
	$(CC) $(SRCS) -o $@ $(CXXFLAGS)

$(BUILDDIR)/$(EXEC_TEST): $(SRC_TEST)
	$(MKDIR_P) $(dir $@)
	$(CC) $(CXXFLAGS) vec.cpp $(SRC_TEST) $(TESTFLAGS) -o $@

.PHONY: test
test: $(BUILDDIR)/$(EXEC_TEST)
	$(BUILDDIR)/$(EXEC_TEST)

.PHONY: coverage
coverage: $(BUILDDIR)/$(EXEC_TEST)
	lcov --capture --directory . -b . --output-file $(BUILDDIR)/coverage.info
	lcov --remove $(BUILDDIR)/coverage.info -o $(BUILDDIR)/stripped_coverage.info "/usr/include/*"
	genhtml $(BUILDDIR)/stripped_coverage.info --output-dir $(BUILDDIR)/reports

.PHONY: clean
clean:
	$(RM) -r $(BUILDDIR)
	rm *gcda *gcno

MKDIR_P ?= mkdir -p
