(*docker build -t ocaml .*)
(*docker run --rm -i -t ocaml*)

let square x = x * x;;

let rec fact x =
    if x <= 1 then 1 else x * fact (x - 1);;


print_int(square 3);;
let _ = print_endline " = Square of 3" in
print_int(fact 3);;
let _ = print_endline " = 3 * 2" in
print_int(square 6);;
let _ = print_endline " = square of 6" in
print_int(fact 6);;
let _ = print_endline " = 6 * 5" in
let _ = print_endline "Hello" in
let _ = print_endline "World" in
let _ = print_endline "My name is" in
print_endline "Nate"

