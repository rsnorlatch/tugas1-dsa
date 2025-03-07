all: clean build run

build:
	mkdir build
	mkdir plist
	clang++ --analyze ./*.cpp -o ./plist/a.plist
	clang++ ./*.cpp -o ./build/a.exe

clean:
	rm -r ./build
	rm -r ./plist

run:
	@exec ./build/a.exe

