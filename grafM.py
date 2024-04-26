import matplotlib.pyplot as plt

# Data
set_sizes = list(range(1, 20))
avg_porovnanie_prienik = [0.01, 0.08, 0.08, 0.12, 0.26, 0.42, 0.49, 0.61, 0.84, 0.89, 1.05, 1.42, 1.50, 1.91, 2.19, 2.35, 2.56, 2.73, 3.38]
avg_porovnanie_zjednotenie = [1.99, 3.92, 5.92, 7.88, 9.74, 11.58, 13.52, 15.40, 17.15, 19.10, 20.91, 22.60, 24.45, 26.02, 27.82, 29.56, 31.48, 33.28, 34.55]

# Graf
plt.figure(figsize=(10, 6))
plt.plot(set_sizes, avg_porovnanie_prienik, label='Prienik', marker='o')
plt.plot(set_sizes, avg_porovnanie_zjednotenie, label='Zjednotenie', marker='o')
plt.xlabel('Počet prvkov množiny')
plt.ylabel('Priemerný počet porovnaní')
plt.legend()
plt.grid(True)
plt.show()