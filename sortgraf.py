import matplotlib.pyplot as plt

# Data
set_sizes = list(range(0, 20))
averages_intersection = [1.00, 3.98, 8.94, 15.69, 24.63, 35.19, 47.36, 62.13, 77.82, 95.49, 115.79, 136.92, 158.57, 183.53, 208.73, 238.05, 267.59, 296.48, 327.92, 365.05]
averages_union = [2.00, 5.98, 11.95, 19.71, 29.58, 41.14, 54.63, 69.99, 86.68, 105.77, 126.60, 148.69, 171.32, 197.80, 224.67, 253.92, 284.65, 314.66, 347.94, 386.69]
# Graf
plt.figure(figsize=(10, 6))
plt.plot(set_sizes, averages_intersection, label='Prienik 2')
plt.plot(set_sizes, averages_union, label='Zjednotenie 2')
plt.xlabel('Počet prvkov množiny')
plt.ylabel('Priemerný počet porovnaní')
plt.legend()
plt.grid(True)
plt.show()