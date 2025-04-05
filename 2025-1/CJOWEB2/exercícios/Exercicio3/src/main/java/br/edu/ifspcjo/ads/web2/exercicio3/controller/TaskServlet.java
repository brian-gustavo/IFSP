package controller;

import model.Task;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import java.io.*;
import java.util.*;

public class TaskServlet extends HttpServlet
{
    private List<Task> tasks = new ArrayList<>();
    private int taskIdCounter = 1;

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) 
    		throws ServletException, IOException
    {
        request.setAttribute("tasks", tasks);
        RequestDispatcher dispatcher = request.getRequestDispatcher("lista.jsp");
        dispatcher.forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) 
    		throws ServletException, IOException 
    {
        String description = request.getParameter("description");
        String date = request.getParameter("date");

        Task newTask = new Task(taskIdCounter++, description, date);
        tasks.add(newTask);

        request.setAttribute("tasks", tasks);
        
        RequestDispatcher dispatcher = request.getRequestDispatcher("lista.jsp");
        dispatcher.forward(request, response);
    }
}
