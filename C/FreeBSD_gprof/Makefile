main:	main.c
	cc -pg -o main main.c
	

run:	main
	./main
	gprof main | grep hog 

clean:
	rm -rf main main.gmon
	
	
	
