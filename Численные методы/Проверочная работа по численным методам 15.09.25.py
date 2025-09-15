import math

def InputNum(var:str)->float:
    
    while True:
        
        try:
        
            num = float(eval(input(var)))
            
            print(f"var = {num}")
            
            return num
        
        except Exception as err:
            
            print(err)

def AbsouteErr(n,n1)->float:
    
    return abs(n-n1)

def RelativeErr(delta_n,n)->float:
    
    return abs(delta_n)/n

while True:
    
    a1 = InputNum("a:")
    b1 = InputNum("b:")
    
    a = round(a1,3)
    b = round(b1,3)

    delta_a = AbsouteErr(a,a1)
    delta_b = AbsouteErr(b,b1)
    
    Delta_A = RelativeErr(delta_a,a)
    Delta_B = RelativeErr(delta_b,b)
    
    print(f"\na = {a}\nb = {b}\na1 = {a1}\nb1 = {b1}\ndelta a = |a - a1| = |{a} - {a1}| = {delta_a}\ndelta b = |b - b1| = |{b} - {b1}| = {delta_b}\nDELTA A = |delta a| / a = |{delta_a}| / {a} = {Delta_A}\nDELTA B = |delta b| / b = |{delta_b}| / {b} = {Delta_B}\n")
    
    if Delta_A < Delta_B:
        print(f"The variable A is more precise\n")
        
    elif Delta_A > Delta_B:
        print(f"The variable B is more precise\n")
    
    else:
        print(f"Variables are equally accurate\n")