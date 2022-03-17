
manager_worker(nicole, jeff).
manager_worker(nicole, jerry).
manager_worker(pat, allan).
manager_worker(pat, gabe).

brand_worker(nike, john).
brand_worker(apple, bob).
brand_worker(apple, allan).
brand_worker(google, mike).
brand_worker(google, tim).

coworkers(X, Y)      :- company_worker(Z, X), company_worker(Z, Y).

company_worker(X, Y) :- brand_worker(X, Y).
company_worker(X, Y) :- manager_worker(X, Y).