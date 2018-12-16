make: clean build

build:
	./latexrun shader-presentation.tex

clean:
	@rm -f *.log shader-presentation.out *.snm *.toc *.aux *.nav
