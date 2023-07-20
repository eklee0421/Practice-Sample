package com.turnit.sidePractice.service;

import com.turnit.sidePractice.domain.Member;
import com.turnit.sidePractice.repository.MemberRepository;
import com.turnit.sidePractice.repository.MemoryMemberRepository;

public class MemberService {

    private final MemberRepository memberRepository = new MemoryMemberRepository();

    /**
    * 회원 가입
    * */
    public Long join(Member member){

        //같은 이음이 있는 중복 회원은 불가
        memberRepository.findByName(member.getName())
                .ifPresent(m ->{
                    throw new IllegalStateException("이미 존재하는 회원입니다.");
                });

        memberRepository.save(member);
        return member.getId();
    }
}
