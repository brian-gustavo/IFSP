package br.edu.ifspcjo.ads.web3.exercicio2.domain.controller;

import br.edu.ifspcjo.ads.web3.exercicio2.dto.CategoryDTO;
import br.edu.ifspcjo.ads.web3.exercicio2.domain.model.Category;
import br.edu.ifspcjo.ads.web3.exercicio2.service.CategoryService;
import jakarta.validation.Valid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/categories")
public class CategoryController {
    @Autowired
    private CategoryService categoryService;

    @PostMapping
    public ResponseEntity<Category> createCategory(@Valid @RequestBody CategoryDTO categoryDTO) {
        Category category = categoryService.createCategory(categoryDTO);
        return ResponseEntity.status(HttpStatus.CREATED).body(category);
    }
}
