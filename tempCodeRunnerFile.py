import matplotlib.pyplot as plt

# Data
set_sizes = list(range(0, 20))
averages_intersection = [0.01, 0.05, 0.09, 0.12, 0.31, 0.26, 0.61, 0.54, 0.73, 0.98, 1.13, 1.51, 1.58, 1.73, 2.01, 2.45, 2.37, 3.07, 3.07, 3.26]
averages_union = [0.01, 0.05, 0.08, 0.12, 0.31, 0.28, 0.57, 0.54, 0.72, 0.95, 1.12, 1.44, 1.56, 1.72, 1.97, 2.46, 2.37, 3.07, 3.15, 3.25]
# Graf
plt.figure(figsize=(10, 6))
plt.plot(set_sizes, averages_intersection, label='Prienik')
plt.plot(set_sizes, averages_union, label='Zjednotenie')
plt.xlabel('Počet prvkov množiny')
plt.ylabel('Priemerný počet porovnaní')
plt.legend()
plt.grid(True)
plt.show()