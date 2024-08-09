#include "blur_filter.h"
#include "image.h"
#include "negative_filter.h"
#include "pixelate_filter.h"
#include "sepia_filter.h"
#include "task.h"
#include <fstream>
#include <iostream>
#include <string>
#include <queue>

void processTask(Task &task);

int main(int argc, char *argv[]) {
  while (argc < 2) {
    std::cerr << "Uso: ./ejecutable <archivo_de_tareas.txt>" << std::endl;
    return 1;
  }

  std::string tasksFileName = argv[1];
  std::ifstream TasksFile(tasksFileName);

  if (!TasksFile.is_open()) {
    std::cerr << "Error al abrir el archivo de tareas: " << tasksFileName
              << std::endl;
    return 1;
  }

  std::queue<Task> tasks;

  int numTasks;
  TasksFile >> numTasks;

  for (int i = 0; i < numTasks; ++i) {
    Task task;
    TasksFile >> task.id >> task.inputFileName >> task.outputFileName >> task.filterName;
    tasks.push(task);
  }

  TasksFile.close();

  //Mensaje de confirmacion de que todo salio vien al leer el arhivo
  std::cout << "Archivo de tareas leído correctamente" << std::endl;

  while (!tasks.empty()) {
    Task task = tasks.front();
    tasks.pop();
    processTask(task);
  }

  return 0;
}

void processTask(Task &task) {
  Image image(task.inputFileName);
  try {
    // Aplicar el filtro según el nombre especificado

    if (task.filterName == "blur") {
      BlurFilter blurFilter;
      blurFilter.apply(image);
      std::cout << "Filtro de desenfoque aplicado correctamente" << std::endl;
    } else if (task.filterName == "sepia") {
      SepiaFilter sepiaFilter;
      sepiaFilter.apply(image);
      std::cout << "Filtro sepia aplicado correctamente" << std::endl;
    } else if (task.filterName == "negative") {
      NegativeFilter negativeFilter;
      negativeFilter.apply(image);
      std::cout << "Filtro negativo aplicado correctamente" << std::endl;
    } else if (task.filterName == "pixelate") {
      PixelateFilter pixelateFilter;
      pixelateFilter.apply(image, 10);
      std::cout << "Filtro de pixelado aplicado correctamente" << std::endl;
    } else {
      std::cerr << "Filtro no válido: " << task.filterName << std::endl;
      return;
    }
    } catch (const std::exception& e) {
    std::cerr << "Error al procesar la tarea ID " << task.id << ": " << e.what()
              << std::endl;
  }

  image.save(task.outputFileName);

  std::cout << "Filtro aplicado y guardado en " << task.outputFileName
            << " (Task ID: " << task.id << ")" << std::endl;
}