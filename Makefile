client_p03_cya: backpack_problem.cc backpack.cc item.cc
	g++ -o backpack_problem backpack_problem.cc backpack.cc item.cc

clean:
	rm -r backpack_problem