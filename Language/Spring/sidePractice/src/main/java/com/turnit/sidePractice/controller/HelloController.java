package com.turnit.sidePractice.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HelloController {

    @GetMapping("hello")
    public String hello(Model model){
        model.addAttribute("data", "hello!!");
        return "hello";
    }

    @GetMapping("hello-mvc")
    public String helloMvc(@RequestParam(name = "name") String name, Model model){
        model.addAttribute("name", name);
        return "hello-template";
    }

    @GetMapping("hello-string")
    @ResponseBody   //통신 프로토콜 http의 바디부에 "hello" + name을 직접 넣어주겠다
                    //data가 그대로 내려간다! - 페이지에서 소스보기 하면 문자만 있음
    public String helloString(@RequestParam("neme") String name){
        return "hello" + name;
    }


    ///JSON 방식
    @GetMapping("hello-api")
    @ResponseBody
    public Hello helloApi(@RequestParam("name") String name){
        Hello hello = new Hello();
        hello.setName(name);
        return hello;   //{"name":"spring!!!!!!!!!!"} 으로 나옴
    }

    static class Hello{
        private String name;

        //getter와 setter - 자바빈 표준 방식 (프로퍼티 접근 방식)
        public String getName() {
            return name;
        }

        public void setName(String name){
            this.name = name;
        }
    }
}
