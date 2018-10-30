FLAGS=-std=gnu++14 -O2 -g -Wall -Wextra -Wpedantic -Wfatal-errors

all: answer prob.pdf input output

prob.pdf:
	curl -s 'https://www.hackerrank.com/rest/contests/master/challenges/$(PROBLEM)/download_pdf?language=English' -o $@

input output:
	curl -s 'https://www.hackerrank.com/rest/contests/master/challenges/$(PROBLEM)/download_testcases' -o tests.zip
	unzip tests.zip
	rm tests.zip

output_endls: output
	@# Add a newline to outputs if it doesn't already exist
	@for OFILE in output/* ; do sed -i -e '$$a\' $$OFILE ; done

answer.cpp:
	echo "#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n}" > answer.cpp

answer: answer.cpp
	$(CXX) $(FLAGS) $< -o $@

check: input output_endls answer
	@for PROBNUM in $$(ls input | grep -o -E [[:digit:]]+) ; do \
		./answer < input/input$$PROBNUM.txt > /tmp/temp.ans ; \
	  if ! diff -Z /tmp/temp.ans output/output$$PROBNUM.txt > /dev/null ; then \
		  echo "Failed problem $$PROBNUM" ; \
	  fi \
	done
	@rm /tmp/temp.ans

clean:
	rm -rf answer prob.pdf input output

