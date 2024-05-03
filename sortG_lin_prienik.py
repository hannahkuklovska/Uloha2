import matplotlib.pyplot as plt

#Pozorovateľná linearita vo forme implementácie prieniku 

# Data
set_sizes = list(range(0, 20))
averages_intersection = [1.00, 2.67, 4.52, 6.22, 7.95, 10.27, 11.76, 13.66, 15.39, 17.33,
                   19.36, 20.74, 22.42, 24.39, 26.02, 28.15, 30.10, 31.66, 32.84, 34.85]
averages_union = [2.00, 5.98, 11.90, 19.65, 29.55, 41.42, 54.21, 69.79, 86.54, 105.34,
                       127.02, 146.79, 172.22, 198.38, 224.27, 254.55, 285.66, 317.26, 347.12, 382.85]
# Graf
plt.figure(figsize=(10, 6))
plt.plot(set_sizes, averages_intersection, label='Prienik 3 (lin)')
plt.plot(set_sizes, averages_union, label='Zjednotenie 3')
plt.xlabel('Počet prvkov množiny')
plt.ylabel('Priemerný počet porovnaní')
plt.legend()
plt.grid(True)
plt.show()