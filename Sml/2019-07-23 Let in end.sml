fun fact(n) = 
	let
		fun fact_tr(n) = fn res =>
			if n = 0 then
				res
			else
				fact_tr (n-1) (n*res)
	in
		fact_tr(n) 1
	end;
fact 5;