import matplotlib.pyplot as plt

# Data
set_sizes = list(range(0, 20))
avg_porovnanie_prienik = [1, 5, 10, 17, 23, 28, 52, 57, 77, 106, 121, 158, 155, 186, 199, 238, 261, 277, 331, 386]
avg_porovnanie_zjednotenie = [1, 5, 10, 17, 24, 27, 53, 58, 79, 98, 116, 161, 155, 193, 201, 240, 260, 285, 338, 374]

# Graf
plt.figure(figsize=(10, 6))
plt.plot(set_sizes, avg_porovnanie_prienik, label='Prienik')
plt.plot(set_sizes, avg_porovnanie_zjednotenie, label='Zjednotenie')
plt.xlabel('Počet prvkov množiny')
plt.ylabel('Priemerný počet porovnaní')
plt.legend()
plt.grid(True)
plt.show()