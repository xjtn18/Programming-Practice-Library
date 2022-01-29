ifndef f
	f := a
endif
ifndef t
	t := 1
endif

headers := helper.hpp save.hpp
exec := out

$(exec) : onepizzaOLD.cpp $(headers)
	@ echo Compiling ...
	@ g++ -std=c++17 -I. $< -o $@ -O3
	@ echo Compilation finished.

buildload : $(exec)
	@ ./$(exec) LOAD $(t) $(f).txt

buildsave : $(exec)
	@ ./$(exec) SAVE $(t) $(f).txt

load :
	@ ./$(exec) LOAD $(t) $(f).txt

save :
	@ ./$(exec) SAVE $(t) $(f).txt

runonly :
	@ ./$(exec)

clean :
	@ rm $(exec)

