INCLUDES=-Iinclude
CXXFLAGS=-std=c++20 -Wall -Wextra -Wpedantic -ggdb $(INCLUDES)
CXX=g++

exec: bin/profile
	$<

tests: bin/tests
	$<

clean:
	rm -rf ./bin/*

bin/profile: src/main.cc src/db.cc src/utils.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

bin/tests: tests/*.cc src/db.cc src/utils.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

src/%.cc: include/%.hpp
	touch $@

.DEFAULT_GOAL=tests
.PHONY: exec tests clean
