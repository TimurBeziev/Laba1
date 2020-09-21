#include <windows.h>
#include <windowsx.h>
#include <cmath>
#include <string>
#include <vector>
#include "controller.h"

LRESULT MessagesHandler(
    HWND window_handle, UINT message_code, WPARAM w_param, LPARAM l_param);

HINSTANCE instance_handle;

INT WinMain(HINSTANCE instance_handle_arg, HINSTANCE,
            LPSTR /* command_line */, int n_cmd_show) {
  instance_handle = instance_handle_arg;

  // Register the window class.
  const char kClassName[] = "msg_server_class";
  WNDCLASS window_class = {};
  window_class.lpfnWndProc = MessagesHandler;
  window_class.hInstance = instance_handle;
  window_class.lpszClassName = kClassName;
  window_class.hCursor = LoadCursor(nullptr, IDC_ARROW);
  window_class.hbrBackground = GetStockBrush(WHITE_BRUSH);
  RegisterClass(&window_class);

  // Create the window.
  HWND handle_of_window = CreateWindowEx(
      /* dwExStyle =    */ 0,
      /* lpClassName =  */ kClassName,
      /* lpWindowName = */ "WinAPI Example",
      /* dwStyle =      */ WS_OVERLAPPEDWINDOW,
      /* X =            */ CW_USEDEFAULT,
      /* Y =            */ CW_USEDEFAULT,
      /* nWidth =       */ 500,
      /* nHeight =      */ 500,
      /* hWndParent =   */ nullptr,
      /* hMenu =        */ nullptr,
      /* hInstance =    */ instance_handle,
      /* lpParam =      */ nullptr
  );
  if (handle_of_window == nullptr) {
    return 1;
  }

  // Show the window.
  ShowWindow(handle_of_window, n_cmd_show);

  // Run the message loop.
  MSG message = {};
  while (GetMessage(&message, nullptr, 0, 0)) {
    TranslateMessage(&message);
    DispatchMessage(&message);
  }

  return (int) message.wParam;
}

LRESULT MessagesHandler(
    HWND window_handle, UINT message_code, WPARAM w_param, LPARAM l_param) {
  static Controller* controller;
  static HWND add_professor_button;
  static HWND add_student_button;
  static HWND next_person_button;

  switch (message_code) {
    case WM_CREATE: {
      controller = new Controller();
      add_professor_button = CreateWindow(
          "button",
          "Add Professor",
          WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
          300,
          10,
          100,
          30,
          window_handle,
          (HMENU) WM_USER,
          instance_handle,
          nullptr);
      add_student_button = CreateWindow(
          "button",
          "Add Student",
          WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
          20,
          10,
          90,
          30,
          window_handle,
          (HMENU) WM_USER,
          instance_handle,
          nullptr);
      next_person_button = CreateWindow(
          "button",
          "Next Person",
          WS_CHILD | WS_VISIBLE | WS_BORDER | BS_PUSHBUTTON,
          300,
          400,
          150,
          30,
          window_handle,
          (HMENU) WM_USER,
          instance_handle,
          nullptr);
      break;
    }
    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(window_handle, &ps);
      controller->Draw(hdc);
      EndPaint(window_handle, &ps);
      break;
    }
    case WM_COMMAND: {
      if ((HWND) l_param == add_professor_button) {
        controller->AddProfessor();
        InvalidateRect(window_handle, nullptr, true);
      } else if ((HWND) l_param == add_student_button) {
        controller->AddStudent();
        InvalidateRect(window_handle, nullptr, true);
      } else if ((HWND) l_param == next_person_button) {
        controller->NextPerson();
        InvalidateRect(window_handle, nullptr, true);
      }
      break;
    }
    case WM_DESTROY: {
      PostQuitMessage(0);
      break;
    }
    default: {
      return DefWindowProc(window_handle, message_code, w_param, l_param);
    }
  }
  return 0;
}
