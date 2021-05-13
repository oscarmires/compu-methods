
/* 
 * Actividad 5.1
 */

% 2
vowel(a).
vowel(e).
vowel(i).
vowel(o).
vowel(u).

deconsonant([H|T]):-
    (   vowel(H) ->  
        writeln(H),
        deconsonant(T);
        deconsonant(T)
    ).

% 5
last([], _):-
    fail.
last([H], H). 
last([_|T], U):-
    last(T, U).

% 6


% 7
fact(0, 1).
fact(N, F):-
    N > 0,
    N_1 is N - 1,
    fact(N_1, F_1),
    F is F_1 * N.

% 9 
length2([], 0).
length2([_|T], L):-
    length2(T, L_1),
    L is L_1 + 1.

% 10


% 16
sum([], _):-
    fail.
sum([H], S):-
    S is H.
sum([H|T], S):-
    sum(T, S_1),
    S is H + S_1.
