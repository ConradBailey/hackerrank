FLAGS=-std=gnu++14 -O2 -Wall -Wextra -Wpedantic -Wfatal-errors

all: answer prob.pdf tests

prob.pdf:
	curl -s 'https://www.hackerrank.com/rest/contests/master/challenges/$(PROBLEM)/download_pdf?language=English' -o $@

tests: input output

input:
	curl -s 'https://www.hackerrank.com/rest/contests/master/challenges/$(PROBLEM)/download_testcases' -o tests.zip
	unzip tests.zip
	rm tests.zip

output: input

answer: answer.cpp
	$(CXX) $(FLAGS) $< -o $@

check: input output answer
	@for PROBNUM in $$(ls input | grep -o -E [[:digit:]]+) ; do \
		./answer < input/input$$PROBNUM.txt > /tmp/temp.ans ; \
	  if ! diff /tmp/temp.ans output/output$$PROBNUM.txt > /dev/null ; then \
		  echo "Failed problem $$PROBNUM" ; \
	  fi \
	done
	@rm /tmp/temp.ans

clean:
	rm -rf answer prob.pdf input output

