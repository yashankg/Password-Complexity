import re

def assess_password_strength(password):
    strength_criteria = {
        "length": len(password) >= 8,
        "uppercase": re.search(r"[A-Z]", password) is not None,
        "lowercase": re.search(r"[a-z]", password) is not None,
        "numbers": re.search(r"[0-9]", password) is not None,
        "special_characters": re.search(r"[!@#$%^&*(),.?\":{}|<>]", password) is not None
    }

    strength_score = sum(strength_criteria.values())
    
    feedback = []
    if not strength_criteria["length"]:
        feedback.append("Password should be at least 8 characters long.")
    if not strength_criteria["uppercase"]:
        feedback.append("Password should include at least one uppercase letter.")
    if not strength_criteria["lowercase"]:
        feedback.append("Password should include at least one lowercase letter.")
    if not strength_criteria["numbers"]:
        feedback.append("Password should include at least one number.")
    if not strength_criteria["special_characters"]:
        feedback.append("Password should include at least one special character.")
    
    if strength_score == 5:
        feedback.append("Your password is strong.")
    elif 3 <= strength_score < 5:
        feedback.append("Your password is moderate.")
    else:
        feedback.append("Your password is weak.")
    
    return feedback

def main():
    password = input("Enter your password: ")
    feedback = assess_password_strength(password)
    
    print("\nPassword Feedback:")
    for comment in feedback:
        print(f"- {comment}")

if __name__ == "__main__":
    main()
