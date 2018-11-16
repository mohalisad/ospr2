all:worker lb presenter
worker:worker.o strtoken.o table.o row.o
	g++ -o worker worker.o strtoken.o table.o row.o
lb:lb.o workersmanager.o inpparse.o strtoken.o strlib.o
	g++ -o lb lb.o workersmanager.o inpparse.o strtoken.o strlib.o
presenter:presenter.o
	g++ -o presenter presenter.o
inpparse.o:inpparse.cpp inpparse.h strtoken.h strlib.h
	g++ -c inpparse.cpp
lb.o:lb.cpp workersmanager.h inpparse.h
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
worker.o: worker.cpp strtoken.h filter.h table.h
	g++ -c worker.cpp
workersmanager.o: workersmanager.cpp workersmanager.h
	g++ -c workersmanager.cpp
inpparse.h:filter.h
row.h:strtoken.h filter.h
table.h:strtoken.h row.h
clean:
	rm -rf *.o lb worker presenter
