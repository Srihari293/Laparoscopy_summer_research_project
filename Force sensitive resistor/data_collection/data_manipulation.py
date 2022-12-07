
# Importing data in csv file into a dataframe
file_path = "Force sensitive resistor\data_collection\voltage_data.csv"
df = pd.read_csv(file_path)
df.head(5)