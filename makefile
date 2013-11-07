all : plot colision

plot : ini.x evolv.x
	./ini.x 0.0 0.0 0.0 0.0
	./evolv.x
	python plots.py data*

evolv.x : rungekutta.c
	 cc rungekutta.c -lm -o evolv.x

ini.x : avanceshw6.c
	cc avanceshw6.c -lm -o ini.x

colision : again data1.dat
	./ini.x 150.0 200.0 0.0 1.02e-7 
	./evolv.x
	python plots.py data*

again : 
	rm data2.dat data3.dat data4.dat data5.dat data6.dat 

clean : 
	rm data* *.x
