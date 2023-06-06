#!/bin/bash

rm -f *.aux *.toc *.lot *.tof *.log *.out *.aux *.bbl *.bcf *.thm

echo -e "\npdflatex iteration 1:\n\n"
# use texfot to reduce verbosity:
if texfot pdflatex -shell-escape -interaction=nonstopmode -file-line-error Solutions.tex ; then
    echo -e "\n\n\nrunning biber:\n\n"
#    texfot bibtex8 Solutions
    texfot biber Solutions
    echo -e "\n\n\npdflatex iteration 2:\n\n"
    texfot pdflatex -shell-escape -interaction=nonstopmode -file-line-error Solutions.tex
    echo -e "\n\n\npdflatex iteration 3:\n\n"
    texfot pdflatex -shell-escape -interaction=nonstopmode -file-line-error Solutions.tex

else
#    if texfot not available:
    echo -e "\ntrying to recover by not using texfot"
    pdflatex -shell-escape -interaction=nonstopmode -file-line-error Solutions.tex | grep -i ".*:[0-9]*:.*\|warning"
    echo -e "\n\n\nrunning biber:\n\n"
#    bibtex8 Solutions
    biber Solutions
    echo -e "\n\n\npdflatex iteration 2:\n\n"
    pdflatex -shell-escape -interaction=nonstopmode -file-line-error Solutions.tex | grep -i ".*:[0-9]*:.*\|warning"
    echo -e "\n\n\npdflatex iteration 3:\n\n"
    pdflatex -shell-escape -interaction=nonstopmode -file-line-error Solutions.tex | grep -i ".*:[0-9]*:.*\|warning"
fi


rm -f *.aux *.toc *.lot *.tof *.log *.lof *.blg *.out *.aux *.bbl *.bcf *.thm *.run.xml

