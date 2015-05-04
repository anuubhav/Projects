## DB Test Explanation

### Redekopp POV

Calculations are performed from Redekopp's POV. Please log in with "redekopp" and "password". 

#### Basic similarities:
- redekopp -> ttrojan, .25
- redekopp -> everyone else, 1

Redekopp only has one review and shares it with ttrojan.

#### Refined similarities:
- redekopp -> ttrojan, .25
- redekopp -> peter, .5
- redekopp -> aaroncot, .75
- redekopp -> everyone else, 1

Redekopp shares a review with ttrojan, ttrojan shares a review with peter, peter shares a review with aaroncot. These basic similarities are .25. All other basic similarities are 1.

#### Product Recommendations
1. Men's Fitted Shirt - 5
1. C++ Primer - 4.6
1. Interstellar Blu-ray - 4
1. Whiplash DVD - 3
1. Data Abstraction & Problem Solving with C++ - 2.33333

Example calculation for C++ primer (ttrojan & peter reviewed):

R(P) = (1 - 0.25)(5) + (1 - 0.5)(4)

W = (1 - 0.25) + (1 - 0.5)

R(P)/W = 4.6

### Peter POV

Calculations are performed from Peter's POV. Please log in with "peter" and "csci104".

#### Basic similarities: 
- peter -> aaroncot, .25
- peter -> ttrojan, .25
- peter -> everyone else, 1

#### Refined similarities:
- peter -> aaroncot, .25
- peter -> ttrojan, .25
- peter -> redekopp, .5
- peter -> everyone else, 1

#### Product Recommendations
1. Men's Fitted Shirt - 5
1. The C++ Programming Language - 3.4
1. Interstellar Blu-ray - 3
