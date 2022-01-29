headers := helper.hpp
exec := out

$(exec) : onepizza.cpp $(headers)
	@ echo Compiling ...
	@ g++ -std=c++17 -I. $< -o $@ -O3
	@ echo Compilation finished.

run : $(exec)
	@ ./$(exec)

runonly :
	@ ./$(exec)

clean :
	@ rm $(exec)

