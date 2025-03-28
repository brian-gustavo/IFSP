package controller;

import model.Usuario;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/login")
public class LoginServlet extends HttpServlet
{
    private static final String EMAIL_VALIDO = "usuario@exemplo.com";
    private static final String SENHA_VALIDA = "senha123";

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) 
    	throws ServletException, IOException {
	        String email = request.getParameter("email");
	        String senha = request.getParameter("senha");
	
	        Usuario usuario = new Usuario();
	        usuario.setEmail(email);
	        usuario.setSenha(senha);
	
	        if (EMAIL_VALIDO.equals(email) && SENHA_VALIDA.equals(senha)) {
	            request.setAttribute("usuario", usuario);
	            request.getRequestDispatcher("/bemvindo.jsp").forward(request, response);
	        } else {
	            request.getRequestDispatcher("/erro.jsp").forward(request, response);
	        }
    	}

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    	throws ServletException, IOException {
        	request.getRequestDispatcher("/login.jsp").forward(request, response);
    	}
}
