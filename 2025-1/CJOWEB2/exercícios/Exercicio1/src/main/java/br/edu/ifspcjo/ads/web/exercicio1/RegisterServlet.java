package br.edu.ifspcjo.ads.web.exercicio1;

import java.io.IOException;
import java.io.PrintWriter;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet("/register")
public class RegisterServlet extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	public RegisterServlet()
	{
		super();
	}

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) 
		throws ServletException, IOException {
			req.setCharacterEncoding("UTF-8");
			String name = req.getParameter("name");
			String email = req.getParameter("email");
			String email2 = req.getParameter("email2");
			String[] options = req.getParameterValues("options");
			String selectedOptions = "";
			
			if(options != null)
			{
				for(String option : options)
				{
					selectedOptions += option + " ";
				}
			}
			
			resp.setContentType("text/html;charset=UTF-8");
			PrintWriter writer = resp.getWriter();
			writer.println("<!DOCTYPE html>");
			writer.println("<html lang=\"pt-BR\">");
			writer.println("<head>");
			writer.println("\t<meta charset=\"UTF-8\">");
			writer.println("\t<title>Página de confirmação</title>");
			writer.println("</head>");
			writer.println("<body>");
			writer.println("\t<h1>Cadastro realizado com sucesso!</h1>");
			writer.println("\t<h2>Nome: " + name + "</h2>");
			writer.println("\t<h2>Email: " + email + "</h2>");
			writer.println("\t<h2>Email secundário: " + email2 + "</h2>");
			writer.println("\t<h2>Cursos nos quais se cadastrou: " + selectedOptions + "</h2>");
			writer.println("</body>");
			writer.println("</html>");
		}
	
	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) 
		throws ServletException, IOException 
		{
			doGet(req, resp);
		}
}
