import tkinter as tk
from tkinter import filedialog, messagebox

# Node for doubly linked list
class TextStateNode:
    def __init__(self, content):
        self.content = content
        self.prev = None
        self.next = None

# Custom Undo/Redo manager using doubly linked list
class UndoRedoManager:
    def __init__(self, initial_text=""):
        self.head = TextStateNode(initial_text)
        self.current = self.head

    def add_state(self, content):
        new_node = TextStateNode(content)
        new_node.prev = self.current
        self.current.next = new_node
        self.current = new_node

    def undo(self):
        if self.current.prev:
            self.current = self.current.prev
            return self.current.content
        return None

    def redo(self):
        if self.current.next:
            self.current = self.current.next
            return self.current.content
        return None

# Main Text Editor App
class TextEditor:
    def __init__(self, root):
        self.root = root
        self.root.title("Tkinter Text Editor with Undo/Redo")
        self.filename = None

        self.text_area = tk.Text(root, undo=False, wrap="word")
        self.text_area.pack(fill="both", expand=1)

        # State manager
        self.undo_redo = UndoRedoManager()

        # Menu
        self.create_menu()

        # Event bindings
        self.text_area.bind("<KeyRelease>", self.track_changes)

    def create_menu(self):
        menubar = tk.Menu(self.root)

        # File Menu
        filemenu = tk.Menu(menubar, tearoff=0)
        filemenu.add_command(label="New", command=self.new_file)
        filemenu.add_command(label="Open", command=self.open_file)
        filemenu.add_command(label="Save", command=self.save_file)
        filemenu.add_separator()
        filemenu.add_command(label="Exit", command=self.root.quit)
        menubar.add_cascade(label="File", menu=filemenu)

        # Edit Menu
        editmenu = tk.Menu(menubar, tearoff=0)
        editmenu.add_command(label="Undo", command=self.undo)
        editmenu.add_command(label="Redo", command=self.redo)
        menubar.add_cascade(label="Edit", menu=editmenu)

        self.root.config(menu=menubar)

    def track_changes(self, event=None):
        content = self.text_area.get("1.0", tk.END)
        self.undo_redo.add_state(content)

    def undo(self):
        content = self.undo_redo.undo()
        if content is not None:
            self.replace_text(content)

    def redo(self):
        content = self.undo_redo.redo()
        if content is not None:
            self.replace_text(content)

    def replace_text(self, content):
        self.text_area.delete("1.0", tk.END)
        self.text_area.insert("1.0", content)

    def new_file(self):
        self.text_area.delete("1.0", tk.END)
        self.undo_redo = UndoRedoManager()

    def open_file(self):
        file = filedialog.askopenfilename(filetypes=[("Text Files", "*.txt")])
        if file:
            self.filename = file
            with open(file, "r") as f:
                content = f.read()
            self.text_area.delete("1.0", tk.END)
            self.text_area.insert("1.0", content)
            self.undo_redo = UndoRedoManager(content)

    def save_file(self):
        if not self.filename:
            self.filename = filedialog.asksaveasfilename(defaultextension=".txt",
                                                         filetypes=[("Text Files", "*.txt")])
        if self.filename:
            with open(self.filename, "w") as f:
                content = self.text_area.get("1.0", tk.END)
                f.write(content.strip())

# Run the editor
if __name__ == "__main__":
    root = tk.Tk()
    app = TextEditor(root)
    root.mainloop()
