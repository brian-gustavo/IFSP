package br.edu.ifspcjo.ads.web3.exercicio3.domain.controller;

import br.edu.ifspcjo.ads.web3.exercicio4.domain.model.Category;
import br.edu.ifspcjo.ads.web3.exercicio4.repository.CategoryRepository;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import jakarta.validation.Valid;

@RestController
@RequestMapping("/categories")
public class CategoryController {
    @Autowired
    private CategoryRepository categoryRepository;
    
    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    public Category create(@Valid @RequestBody Category category) {
        return categoryRepository.save(category);
    }
    
    @PutMapping("/{code}")
    public ResponseEntity<Category> update(@PathVariable Long code, @Valid @RequestBody Category category) {
        Category savedCategory = categoryRepository.findById(code)
                .orElseThrow(() -> new IllegalArgumentException("Categoria não encontrada!"));

        BeanUtils.copyProperties(category, savedCategory, "code");
        return ResponseEntity.ok(categoryRepository.save(savedCategory));
    }

    @DeleteMapping("/{code}")
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void remove(@PathVariable Long code) {
        categoriaRepository.deleteById(code);
    }
}
