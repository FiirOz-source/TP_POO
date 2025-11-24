# Compilateur
CXX = g++

# Options (debug par défaut, parfait pour gdb)
CXXFLAGS = -Wall -Wextra -std=c++17 -g -O0

# Mode release (make release)
ifeq ($(MODE),release)
    CXXFLAGS = -Wall -Wextra -std=c++17 -O3 -DNDEBUG
endif

# Dossier de build
BUILD_DIR = build

# Nom de l'exécutable
TARGET = $(BUILD_DIR)/programme

# Fichiers sources
SRC = main.cpp lib.cpp

# Fichiers objets dans build/
OBJ = $(SRC:%.cpp=$(BUILD_DIR)/%.o)

# Créer le dossier build si besoin
$(shell mkdir -p $(BUILD_DIR))

# ==============================
# Règles
# ==============================

# Par défaut
all: $(TARGET)

# Édition de liens
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)
	@echo "Programme compilé → $(TARGET)"

# Compilation des .cpp → .o dans build/
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage complet
clean:
	rm -rf $(BUILD_DIR)

# Rebuild complet
rebuild: clean all

# Lancer avec gdb
debug: $(TARGET)
	gdb $(TARGET)

# Exécuter
run: $(TARGET)
	./$(TARGET)

# Build optimisé
release:
	make MODE=release

# Phony
.PHONY: all clean rebuild debug run release