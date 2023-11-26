package main

import (
	"encoding/json"
	"fmt"
	"os"
)

type Task struct {
	UserID    int    `json:"user_id"`
	ID        int    `json:"id"`
	Title     string `json:"title"`
	Completed bool   `json:"completed"`
}

type Project struct {
	ProjectID int    `json:"project_id"`
	Tasks     []Task `json:"tasks"`
}

func main() {
	file, err := os.Open("data.json")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	var projects []Project
	if err := json.NewDecoder(file).Decode(&projects); err != nil {
		panic(err)
	}

	var newUserID int
	fmt.Scanf("%d", &newUserID)

	completedTasks := 0
	for i := range projects {
		for j := range projects[i].Tasks {
			if (projects[i].Tasks[j].Completed) && (projects[i].Tasks[j].UserID == newUserID) {
				completedTasks++
			}
		}
	}
	fmt.Println(completedTasks)
}

