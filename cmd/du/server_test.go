package main

import (
	"testing"
)

func TestExample(t *testing.T) {
	expected := "Hello"
	actual := "Hello"
	if expected != actual {
		t.Errorf("expected %s, got %s", expected, actual)
	}
}
