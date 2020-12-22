// Copyright 2020 Your Name <your_email>

#include "Declarations.hpp"

void init() {
  //Настройка логирования
  // Файловый логгер, в который записываются результаты с уровнями логгирования
  // trace и info
  auto fileLoggerTrace = boost::log::add_file_log(
      boost::log::keywords::file_name =
          "/Users/semenpoletin/Labs/logs/"
          "loggerFileTrace_%N.log",
      boost::log::keywords::rotation_size = 10 * 1024 * 1024,
      boost::log::keywords::format =
          "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%");
  // Файловый логгер, в который записываются результаты с уровнем логгирования
  // info
  auto fileLoggerInfo = boost::log::add_file_log(
      boost::log::keywords::file_name =
          "/Users/semenpoletin/3sem/lab-06-multithreads/logs/"
          "loggerFileInfo.log",
      boost::log::keywords::format =
          "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%");
  // Консольный логгер, в который записываются результаты с уровнем логгирования
  // info
  auto consoleLogger = boost::log::add_console_log(
      std::cout, boost::log::keywords::format =
          "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%");

  //Установка фильтрации
  fileLoggerTrace->set_filter(boost::log::trivial::severity >=
                              boost::log::trivial::trace);
  fileLoggerInfo->set_filter(boost::log::trivial::severity ==
                             boost::log::trivial::info);
  consoleLogger->set_filter(boost::log::trivial::severity ==
                            boost::log::trivial::info);
}
