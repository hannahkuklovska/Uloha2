import matplotlib.pyplot as plt

#Pozorovateľná linearita vo forme implementácie prieniku a zjednotenia

# Data
sizes = list(range(1, 21))
average_prienik = [
    1.00, 2.40, 3.58, 5.00, 6.50, 7.90, 9.15, 10.51, 12.17, 13.19, 
    14.75, 16.28, 17.21, 18.65, 20.21, 22.39, 23.78, 24.72, 26.29, 28.29
]
average_zjednotenie = [
    1.99, 3.98, 5.96, 7.94, 9.98, 11.90, 13.93, 15.94, 17.87, 19.91, 
    21.90, 23.71, 25.86, 27.75, 29.80, 31.80, 33.73, 35.75, 37.79, 39.58
]
# Graf
plt.figure(figsize=(10, 6))
plt.plot(sizes, average_prienik, label='Prienik')
plt.plot(sizes, average_zjednotenie, label='Zjednotenie')
plt.xlabel('Počet prvkov množiny')
plt.ylabel('Priemerný počet porovnaní')
plt.legend()
plt.grid(True)
plt.show()