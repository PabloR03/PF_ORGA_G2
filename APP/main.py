import tkinter as tk
from tkinter import font as tkfont
import serial

arduino = serial.Serial(port='COM1', baudrate=9600, timeout=.1)

class BrailleReaderApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Lector de Braille")
        self.center_window(600, 400)
        self.root.resizable(False, False)  # Evita que se pueda modificar el tamaño de la ventana

        # Estilos
        self.root.configure(bg="#f0f0f0")
        title_font = tkfont.Font(family="Helvetica", size=16, weight="bold")
        button_font = tkfont.Font(family="Helvetica", size=12)
        text_font = tkfont.Font(family="Courier", size=12)

        # Título
        title = tk.Label(root, text="Lector de Braille", font=title_font, bg="#f0f0f0", fg="#333333")
        title.pack(pady=10)

        # Frame para el área de texto con scrollbar
        text_frame = tk.Frame(root, bg="#f0f0f0")
        text_frame.pack(pady=10)

        self.text_area = tk.Text(text_frame, height=15, width=50, font=text_font, bg="#ffffff", fg="#000000", relief=tk.FLAT, wrap=tk.WORD)
        self.text_area.pack(side=tk.LEFT)

        scrollbar = tk.Scrollbar(text_frame, command=self.text_area.yview)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        self.text_area.config(yscrollcommand=scrollbar.set)

        # Frame para los botones
        button_frame = tk.Frame(root, bg="#f0f0f0")
        button_frame.pack(pady=10)

        # Botones con cambio de cursor
        self.read_button = tk.Button(button_frame, text="Leer Datos", font=button_font, command=self.read_data, bg="#4caf50", fg="#ffffff", relief=tk.FLAT, padx=10, pady=5, cursor="hand2")
        self.read_button.pack(side=tk.LEFT, padx=10)

        self.reset_button = tk.Button(button_frame, text="Reiniciar Memoria", font=button_font, command=self.reset_memory, bg="#f44336", fg="#ffffff", relief=tk.FLAT, padx=10, pady=5, cursor="hand2")
        self.reset_button.pack(side=tk.LEFT, padx=10)

        self.close_button = tk.Button(button_frame, text="Cerrar", font=button_font, command=self.close_app, bg="#9e9e9e", fg="#ffffff", relief=tk.FLAT, padx=10, pady=5, cursor="hand2")
        self.close_button.pack(side=tk.LEFT, padx=10)

    def center_window(self, width, height):
        screen_width = self.root.winfo_screenwidth()
        screen_height = self.root.winfo_screenheight()
        x = (screen_width // 2) - (width // 2)
        y = (screen_height // 2) - (height // 2)
        self.root.geometry(f'{width}x{height}+{x}+{y}')

    def read_data(self):
        try:
            if arduino.in_waiting > 0:
                data = arduino.read(1)
                value = int.from_bytes(data, byteorder='big')
                char = chr(value)
                self.text_area.insert(tk.END, f"LETRA: {char}\n")
        except Exception as e:
            print(f"Error: {e}")

    def reset_memory(self):
        self.text_area.delete(1.0, tk.END)

    def close_app(self):
        arduino.close()
        self.root.quit()

if __name__ == "__main__":
    root = tk.Tk()
    app = BrailleReaderApp(root)
    root.mainloop()

