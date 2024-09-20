
'''
Niktia Klepikovs, nk24033
A10. Doti divi naturāli skaitļi m un n. Noteikt skaitļa m pirmo n ciparu summu. Skaitļa dalīšana ciparos jāveic skaitliski.
Programma izveidota: 18.09.2024.
'''

'''
 * std::vector<int> extractDigits(long long m)
 * Sadala skaitlu ciparos un atgriež masivu ar tiem
 * m - Skaitlis kuru jasadala ciparos
'''
def extract_digits(m):
    digits = []
    while m > 0: # kamer skaitlis ir lielaks par 0
        digits.append(m % 10)  # izvlikam pedejo ciparu un pievienojam beigas pie masiva
        m //= 10               # dalam skaitli ar 10 un noapalojam uz apaksu, lai dabutu nakošo ciparu

    digits.reverse()           # apgriežam masīvu, lai cipari būtu pareizā secībā
    return digits

ok = 1
while ok != 0:
    # Skaitla ievade no lietotaja
    m = int(input("Ievadiet skaitli m: "))
    n = int(input("Ievadiet skaitli n: "))

    # Parbaude vai ievaditi skaitli (n un m) ir naturali
    if m <= 0 or n <= 0:
        print("Ievadits skaitlis nav naturals")
    else:
        # Izvlikt visus ciparus no skaitla un ierakstit massiva digitsArray
        digitsArray = extract_digits(m)

        # Parbaude vai skaitlim m ir n cipari
        if len(digitsArray) < n:
            print(f"Skaitlim {m} nav {n} ciparu")
        else:
            # saskaitam pirmos n ciparus
            result_sum = sum(digitsArray[:n])
            print(f"Pirmo {n} ciparu summa skaitlim {m} ir {result_sum}")


    # Turpinat vai beigt
    ok = int(input("Vai turpinat (1) vai beigt (0)? "))

'''
m           n       Rezultāts
785938      3       20
123         2       3
123         3       6
9999999     5       45
123         4       Skaitlim 123 nav 4 ciparu
123         0       Ievadits skaitlis nav naturals
0           0       Ievadits skaitlis nav naturals
0           1       Ievadits skaitlis nav naturals
-123        3       Ievadits skaitlis nav naturals
123         -3      Ievadits skaitlis nav naturals
'''