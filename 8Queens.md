	Fajnie ten problem wytłumaczył Dr James Grime na kanale Numberphile.
	https://youtu.be/jPcBU0Z2Hj8
	
		Czy mozemy polozyc 8 hetmanow na szachownicy o rozmiarze 8x8?
				Jakie warunki musi spełniać hetman, aby nie był w czasie ataku?
					*Nie może spotkać się z innym hetmanem w tym samym wierszu
					*Nie może spotkać się z innym hetmanem w tej samej kolumnie
					*Nie może spotkać się z innym hetmanem po przekątnej.
					 				* |x2-x1|==|y2-y1| => Przekatna.
					 				* output[i] == y2 => Czy jest w tej samej kolumnie
					 				* Iterujemy przez wiersze, więc wiersze nigdy nie będą takie same.


		Na ile sposobow mozemy polozyc 8 hetmanow na szachownicy o rozmiarze 8x8?
				*Jest 92 sposoby polozenia gdy spełniony jest warunek, że nie ma ataku
						*Jest 12 sposobów, ale każdy z tych sposobów oprócz jednego ma po 4 rotacje, rotacje szachownicy można uznać za rozwiązanie i 4 odbicia.
						* Czyli jest 8*11+4*1 = 88+4 = 92 rozwiazania
						* Tabela na wikipedii to potwierdza https://en.wikipedia.org/wiki/Eight_queens_puzzle#Counting_solutions ,że dla n =8 jest 92 rozwiazan.
				*Gdyby nie trzeba było spełniać warunku czy hetman jest w czasie ataku, tych kombinacji byłoby (64!)/(56!*8!) = 4 426 165 368
				
				
				
				
					

		

