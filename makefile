all:inpparse.o lb.o presenter.o row.o strlib.o strtoken.o table.o worker.o workermanager.o worker lb
worker:worker.o strtoken.o
	g++ -o worker worker.o strtoken.o
lb:lb.o workermanager.o
	g++ -o lb lb.o workermanager.o
inpparse.o:inpparse.cpp inpparse.h strtoken.h strlib.h
	g++ -c inpparse.cpp
lb.o:lb.cpp workermanager.h
	g++ -c lb.cpp
presenter.o:presenter.cpp
	g++ -c presenter.cpp
row.o:row.cpp row.h table.h
	g++ -c row.cpp
strlib.o: strlib.cpp strlib.h
	g++ -c strlib.cpp
strtoken.o: strtoken.cpp strtoken.h
	g++ -c strtoken.cpp
table.o: table.cpp table.h
	g++ -c table.cpp
worker.o: worker.cpp strtoken.h
	g++ -c worker.cpp
workermanager.o: workermanager.cpp workermanager.h
	g++ -c workermanager.cpp
inpparse.h:filter.h
row.h:strtoken.h
table.h:strtoken.h row.h
clean:
	rm -rf *.o
