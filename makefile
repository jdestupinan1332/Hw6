all : plot

plot : ini.x evolv.x
	./ini.x 0.0 0.0 0.0 0.0
	./evolv.x
		python plots.py data*

evolv.x : rungekutta.c
	 cc rungekutta.c -lm -o evolv.x

ini.x : avanceshw6.c
	cc avanceshw6.c -lm -o ini.x	

clean : 
	rm data* *.x
