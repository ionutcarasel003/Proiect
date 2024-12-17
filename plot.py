import pandas as pd
import matplotlib.pyplot as plt

# Citirea datelor din fișierul CSV
data = pd.read_csv("result.csv")

# Configurarea graficului
plt.figure(figsize=(10, 6))
plt.bar(data["Test Name"], data["Transfer Rate"], color=['blue', 'green', 'red'])

# Adăugarea etichetelor și titlului
plt.xlabel("Test Name", fontsize=12)
plt.ylabel("Transfer Rate (MB/s)", fontsize=12)
plt.title("Compararea vitezelor de transfer pentru diferite nivele de memorie", fontsize=14)
plt.xticks(fontsize=10)
plt.yticks(fontsize=10)

# Adăugarea valorilor deasupra barelor
for i, rate in enumerate(data["Transfer Rate"]):
    plt.text(i, rate + 10000, f"{rate:.0f}", ha='center', fontsize=10)

# Afișarea graficului
plt.tight_layout()
plt.show()
