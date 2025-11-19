plasma:	plasma.cpp
	cc -O3 -lm -o $@ $^

run:	plasma
	./plasma
	ffmpeg -i output-%03d.ppm -r 60 output.mp4

clean:
	rm -rf plasma
	rm -rf output-*.ppm
	rm -rf output.mp4

